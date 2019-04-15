
class Particle {
    constructor(position) {
        this.position = position.copy();
        this.velocity = p5.Vector.random2D();
        this.velocity.setMag(4)
        this.acceleration = createVector();
        this.lifespan = 400;

        this.gravity = createVector(0, .05);
        this.wind = createVector(-.05, 0);
    }

    run() {
        this.addForce(this.gravity);
        this.addForce(this.wind)
        this.update();
        this.show();
    }

    addForce(force) {
        this.acceleration.add(force);
    }

    isDead(){
        return this.lifespan < 0;
    };

    update() {
        this.position.add(this.velocity);
        this.velocity.add(this.acceleration);
        this.velocity.limit(this.maxSpeed);
        this.acceleration.mult(0);
        this.lifespan -= 2;
    }

    show() {
        strokeWeight(8);
        stroke(255);
        point(this.position.x, this.position.y);
    }
}