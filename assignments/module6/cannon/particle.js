const gravity = 0.5;

class Particle {
    constructor(position, target) {
        this.position = position.copy();
        this.velocity = createVector(2, -2);
        this.velocity.setMag(4)
        this.acceleration = createVector();
        this.lifespan = 400;

        if (target) {
            this.aimAt(target);
        }
    }

    run() {
        // this.addForce(this.gravity);
        this.update();
        this.show();
    }

    aimAt(target) {
        let xDist = target.x - this.position.x;
        let yDist = target.y - this.position.y;

        let time = 1;
        let vx = xDist / time;
        let vy = yDist / time + .5 * 1 * time;

        this.velocity.x = vx / 100;
        this.velocity.y = vy / 100;
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