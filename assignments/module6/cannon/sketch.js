let system;

function setup() {
    createCanvas(640, 360);
    system = new ParticleCannon(createVector(0, height));
}

function draw() {
    background(51);
    // let target = createVector(width, height / 2);
    let target = createVector(mouseX, mouseY);

    if (validateTarget(target)) {
        system.addParticle(target);
    }
    system.run();
}

function validateTarget(target) {
    if (target.x > width) return false;
    if (target.x < 0) return false;
    if (target.y > height) return false;
    if (target.y < 0) return false;
    return true;
}