'use strict';


if (!Array.prototype.remove) {
    Array.prototype.remove = function(from, to) {
        var rest = this.slice((to || from) + 1 || this.length);
        this.length = from < 0 ? this.length + from : from;
        return this.push.apply(this, rest);
    };
}

function matrix( rows, cols ){
  var arr = [];
  // Creates all lines:
  for(var i=0; i < rows; i++){
      arr.push([]);
      // Adds cols to the empty line:
      arr[i].push( new Array(cols));
      for(var j=0; j < cols; j++){
        arr[i][j] = new Cell(i,j, (i*rows) + j);
      }
  }

return arr;
}

function drawGrid() {
  let container = document.querySelector('.container');
  container.style.height = 1000 + 'px';
  container.style.width = 1000 + 'px';
  for (var i = 0; i < cells.length; i++) {
    for (var j = 0; j < cells[i].length; j++) {
      container.appendChild(cells[i][j].draw());
    }
  }
}

function Cell(j, i, id) {
  this.xPos = i;
  this.yPos = j;

  this.transversible = true;
  this.startPoint = false;
  this.endPoint = false;

  this.gWeight = 0;
  this.hWeight = 0;
  this.fWeight = 0;

  this.id = id;

  this.closed = false;
  this.visited = false;
  this.elem = null;
  this.parent = null;
}

let cells = matrix(32, 32);


Cell.prototype.draw = function () {
  let cell = document.createElement('div');
  cell.style.backgroundColor = 'grey';
  cell.className = 'gridSquare';
  cell.style.height = 1000/32-3 + 'px';
  cell.style.width = 1000/32-3 + 'px';
  cell.setAttribute('id', this.id)

  if(this.xPos == 0 && this.yPos == 0) {    // If the cell is the first cell
    cell.style.backgroundColor = 'green';   // Make it the startPoint
    cell.transversible = true;
    cell.startPoint = true;
    cell.visited = true;
  } else if(this.xPos == 31 && this.yPos == 31) { // If the cell is the last cell
    cell.style.backgroundColor = 'red';           // Make it the endPoint
    cell.endPoint = true;
  }

  // Creates a 10% chance of every cell becoming an obsticle if its not the start or endPoint
  if((Math.floor(Math.random() * 100) < 10) && !(cell.startPoint) && !(cell.endPoint)) {
    this.transversible = false;
    cell.style.backgroundColor = 'black';
  }
  this.elem = cell;
  return cell;
};


function findNeighbour(matrix, node) {
  let ret = [];

  let x = node.xPos;
  let y = node.yPos;

  if (matrix[x-1] && matrix[x-1][y]) {
    ret.push(matrix[x-1][y]);
  }
  if (matrix[x+1] && matrix[x+1][y]) {
    ret.push(matrix[x+1][y]);
  }
  if (matrix[x] && matrix[x][y+1]) {
    ret.push(matrix[x][y+1]);
  }
  if (matrix[x] && matrix[x][y-1]) {
    ret.push(matrix[x][y-1]);
  }
  return ret;
};


//console.log(findNeighbour(cells, cells[0][0]))

function aStar(matrix, start, stop) {
  let openList = [];

  openList.push(start);
  start.hWeight = heuristics(start, stop);

  while(openList.length > 0) {
    let lowF = 0;
    for (var i = 0; i < openList.length; i++) {
      if (openList[i].fWeight < openList[lowF].fWeight) {
        lowF = i;
      }
    }
    const node = openList[lowF];
    if (node == stop) {
      let curr = node;
      let ret = [];
      while (curr.parent) {
        ret.push(curr);
        curr = curr.parent;
      }
      ret.reverse();
      return ret;
    }
    openList.remove(lowF);
    node.closed = true;

    let neighbors = findNeighbour(matrix, node);
    for (var i = 0; i < neighbors.length; i++) {
      let neighbor = neighbors[i];
      if (!neighbor.transversible || neighbor.closed) {
        continue;
      }
      let gScore = node.gWeight + 1;
      let isBest = false;
      if(!neighbor.visited) {
        isBest = true;
        neighbor.hWeight = heuristics(neighbor, stop);
        neighbor.visited = true;
        openList.push(neighbor);
      } else if(gScore < neighbor.gWeight) {
        isBest = true;
      }
      if (isBest) {
        neighbor.parent = node;
        neighbor.gWeight = gScore;
        neighbor.fWeight = neighbor.gWeight + neighbor.hWeight;
      }
    }
  }
  return [];
}

function heuristics(node, stop) {
  let dx = Math.abs(node.xPos - stop.xPos);
  let dy = Math.abs(node.yPos - stop.yPos);

  return ((dx + dy) * 1);
}


function findPath() {
  let btnText = document.createTextNode('START');
  let start = document.createElement('button');
  start.appendChild(btnText);
  start.setAttribute('class', 'btn');
  document.body.appendChild(start);

  start.onclick = function() {

    let path = aStar(cells, cells[0][0], cells[31][31])

    if(path.length > 0) {
      for (var i = 0; i < path.length; i++) {
        path[i].elem.style.backgroundColor = 'red';
      }
    }

  }
}


drawGrid(); // Draws grid
findPath(); // Applies A* algorythm
