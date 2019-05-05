
// const cols = 13;
// const rows = 10;
// const maze = [
    //     [1,1,1,1,1,1,1,1,1,1,1,1,1],
    //     [1,0,1,0,1,0,1,0,0,0,0,0,1],
    //     [1,0,1,0,0,0,1,0,1,1,1,0,1],
    //     [1,0,0,0,1,1,1,0,0,0,0,0,1],
    //     [1,0,1,0,0,0,0,0,1,1,1,0,1],
    //     [1,0,1,0,1,1,1,0,1,0,0,0,1],
    //     [1,0,1,0,1,0,0,0,1,1,1,0,1],
    //     [1,0,1,0,1,1,1,0,1,0,1,0,1],
    //     [1,0,0,0,0,0,0,0,0,0,1,0,1],
    //     [1,1,1,1,1,1,1,1,1,1,1,1,1]
    // ]
    
const cols = 200;
const rows = 200;
const grid = new Array(cols);

let openSet = [];
let closedSet = [];
let start, end;

let w, h;
let path = [];

const useDiagonals = true;
const obstaclePercentage = 30;

function removeFromArray(array, elem) {
    for (let i = array.length - 1; i >= 0; i--) {
        if (array[i] === elem) {
            array.splice(i, 1);
        }
    }
}

// Raw eucledian distance heuristic
// Should use eucledian with diagonals because diagonals are currently considered the same as vertical and horizontal
function heuristic(a, b) {
    return dist(a.i, a.j, b.i, b.j);
}

// Manhattan type of heuristic using the difference in x and y distance
function manhattan(a, b) {
    return abs(a.i-b.i) + abs(a.j-b.j);
}

function Spot(i, j) {
    this.i = i;
    this.j = j;

    this.f = 0;
    this.g = 0;
    this.h = 0;

    this.wall = false;

    this.neighbors = [];
    this.previous = undefined;

    if (random(1) < obstaclePercentage / 100) {
        this.wall = true;
    }
}

Spot.prototype.show = function(color) {
    fill(color);
    
    if (this.wall)
        fill(0);

    noStroke();
    rect(this.i * w, this.j * h, w-1, h-1);
}

Spot.prototype.addNeighbors = function(grid, useDiagonals) {
    if (this.i < cols-1)
        this.neighbors.push(grid[this.i + 1][this.j]);
    if (this.i > 0)
        this.neighbors.push(grid[this.i - 1][this.j]);
    if (this.j < rows-1)
        this.neighbors.push(grid[this.i][this.j + 1]);
    if (this.j > 0)
        this.neighbors.push(grid[this.i][this.j - 1]);

    if (!useDiagonals) {
        return;
    }
    // Diagonals
    if (this.i > 0 && this.j > 0)
        this.neighbors.push(grid[this.i - 1][this.j - 1]);
    if (this.i > 0 && this.j < rows-1)
        this.neighbors.push(grid[this.i - 1][this.j + 1]);
    if (this.i < cols-1 && this.j > 0)
        this.neighbors.push(grid[this.i + 1][this.j - 1]);
    if (this.i < cols-1 && this.j < rows-1)
        this.neighbors.push(grid[this.i + 1][this.j + 1]);
}


function setup() {
    createCanvas(400, 400);

    w = width / cols;
    h = height / rows;

    // create 2d arr in js
    for (let i = 0; i < cols; i++) {
        grid[i] = new Array(rows);
    }

    for (let i = 0; i < cols; i++) {
        for (let j = 0; j < rows; j++) {
            grid[i][j] = new Spot(i, j);
            // if (maze[j][i]) {
            //     grid[i][j].wall = true;
            // }
        }
    }

    // for (let i = 0; i < cols; i++) {
    //     for (let j = 0; j < rows; j++) {
    //         grid[i][j] = new Spot(i, j);
    //     }
    // }

    // Add neighbors
    for (let i = 0; i < cols; i++) {
        for (let j = 0; j < rows; j++) {
            grid[i][j].addNeighbors(grid, useDiagonals);
        }
    }

    start = grid[0][0]
    end = grid[int(random(cols-1))][int(random(rows/2, rows-1))]

    start.wall = false;
    end.wall = false;

    openSet.push(start);
}

function draw() {
    background(51);
    if (openSet.length > 0) {
        // Current is the node which has the lowest fScore value
        var winner = 0; // The winner / lowestIndex
        for (let i = 0; i < openSet.length; i++) {
            if (openSet[i].f < openSet[winner].f) {
                winner = i;
            }
        }

        var current = openSet[winner];
        if (current === end) {
            noSolution = false;
            noLoop();
            console.log("Found shortest path in " + path.length + " steps");
        }

        removeFromArray(openSet, current);
        closedSet.push(current);

        let neighbors = current.neighbors;
        for (let i = 0; i < neighbors.length; i++) {
            let neighbor = neighbors[i];

            // if (closedSet.includes(neighbor)) {
            //     continue;
            // }
            
            if (!closedSet.includes(neighbor) && !neighbor.wall) {
                // If we are moving to the neighbor, g should increase by 1 -> g is the amount of time to get to the next point
                // Add one because all of the nodes are one apart
                let tmpG = current.g + 1; // Keep this because if the openset includes neighboor it might have a better g value

                // Used to ensure that the gvalue is only used when it is better when !in openset
                var newPath = false;
                if (openSet.includes(neighbor)) {
                    if (tmpG < neighbor.g) {
                        neighbor.g = tmpG;
                        newPath = true; // We have found a better new path
                    }
                } else {
                    neighbor.g = tmpG;
                    newPath = true;  // Has to be new path, since it is the first one
                    openSet.push(neighbor);
                }

                // Only calculate the heuristics if we actually have a new path
                if (newPath) {
                    // Calculate the heuristic
                    neighbor.h = heuristic(neighbor, end);
                    // neighbor.h = manhattan(neighbor, end);
                    // Cost estimate
                    neighbor.f = neighbor.g + neighbor.h;
                    // For tracing path
                    neighbor.previous = current;
                }
            }
        }
    } else {
        console.log("There is no solution");
        noLoop();
        return;
    }

    for (let i = 0; i < cols; i++) {
        for (let j = 0; j < rows; j++) {
            grid[i][j].show(color(255));
        }
    }

    closedSet.map((spot) => {
        spot.show(color(255, 0, 0))
    });

    openSet.map((spot) => {
        spot.show(color(0, 255, 0))
    })

    end.show(color(255,105,180))
    start.show(color(255,105,180))


    // find the path
    path = [];
    let tmp = current;
    path.push(tmp);
    while (tmp.previous) {
        path.push(tmp.previous);
        tmp = tmp.previous;
    }

    path.map((spot) => {
        spot.show(color(0, 0, 255));
    });
}