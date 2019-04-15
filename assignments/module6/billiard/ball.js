
class Ball {
    constructor(position) {
        this.position = position.copy();
        this.velocity = createVector(0, 0);
        this.velocity.setMag(4)
        this.acceleration = createVector();
        this.radius = 10;
        this.mass = 10;
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

    edgeIntersection() {
        if (this.position.x - this.radius < 0) {
            this.velocity.x = -this.velocity.x;
        }
        if (this.position.x + this.radius > width) {
            this.velocity.x = -this.velocity.x;
        }
        if (this.position.y + this.radius > height) {
            this.velocity.y = -this.velocity.y;
        }
        if (this.position.y - this.radius < 0) {
            this.velocity.y = -this.velocity.y;
        }

    }

    update() {
        this.edgeIntersection();
        this.position.add(this.velocity);
        this.velocity.add(this.acceleration);
        this.velocity.limit(this.maxSpeed);
        this.acceleration.mult(0);
    }

    show() {
        strokeWeight(1);
        stroke(255);
        ellipse(this.position.x, this.position.y, this.radius * 2);
    }
}