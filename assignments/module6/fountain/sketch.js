let system;

function setup() {
    createCanvas(640, 360);
    system = new ParticleCannon(createVector(width / 2, height));
}

function draw() {
    background(51);

    system.addParticle();
    system.run();
}