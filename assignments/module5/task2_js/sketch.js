const flock = [];


let alignLvl, cohesionLvl, separationLvl;

function setup() {
    createCanvas(640, 360);
    
    alignLvl = createSlider(0, 2, 1, 0.1);
    cohesionLvl = createSlider(0, 2, 1, 0.1);
    separationLvl = createSlider(0, 2, 1, 0.1);

    alignLvl.position(20, 400);
    cohesionLvl.position(20, 430);
    separationLvl.position(20, 460);

    for (let i = 0; i < 100; i++) {
        flock.push(new Boid());
    }
}

function draw() {
    
    background(51);

    for (let boid of flock) {
        boid.edgeIntersection();
        boid.flock(flock);
        boid.update();
        boid.show();
    }
}