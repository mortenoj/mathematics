class Board {
    constructor() {
        this.balls = [];
    };
    
    addBall(position, initial = false) {
        if (initial) {
            let ball = new Ball(position);
            ball.velocity = createVector(8, 3);
            this.balls.push(ball);
        } else {
            this.balls.push(new Ball(position));
        }
    };

    update() {
      this.balls.map((ball) => { ball.update() })
      this.intersection();
    }

    show() {
      this.balls.map((ball) => { ball.show() })
    }

    intersection() {
        for (let i = 0; i < this.balls.length; i++) {  
            for (let j = i + 1; j < this.balls.length; j++) {  
                let firstBall = this.balls[i];
                let secondBall = this.balls[j];
                if (this.ballsOverlapping(firstBall, secondBall)) {
                    if (this.colliding(firstBall, secondBall)) {
                        this.resolveCollision(firstBall, secondBall);
                    }
                }
            }
        }
    }

    colliding(firstBall, secondBall) {
        if (firstBall === secondBall) return false;
        let distance = sqrt(
            (firstBall.position.x - secondBall.position.x) * (firstBall.position.x - secondBall.position.x) + 
            (firstBall.position.y - secondBall.position.y) * (firstBall.position.y - secondBall.position.y)
        );
        if (distance < firstBall.radius + secondBall.radius) {
            return true;
        }
        return false;
    }

    ballsOverlapping(firstBall, secondBall) {
        if (firstBall === secondBall) return false;
        if (firstBall.position.x + firstBall.radius + secondBall.radius > secondBall.position.x &&
            firstBall.position.x < secondBall.position.x + firstBall.radius + secondBall.radius &&
            firstBall.position.y + firstBall.radius + secondBall.radius > secondBall.position.y &&
            firstBall.position.y < secondBall.position.y + firstBall.radius + secondBall.radius) {
                return true;
        }
        return false;
    }

    resolveCollision(firstBall, secondBall) {
        let newVelX1 = (firstBall.velocity.x * (firstBall.mass - secondBall.mass) + (2 * secondBall.mass * secondBall.velocity.x)) / (firstBall.mass + secondBall.mass);
        let newVelY1 = (firstBall.velocity.y * (firstBall.mass - secondBall.mass) + (2 * secondBall.mass * secondBall.velocity.y)) / (firstBall.mass + secondBall.mass);
        let newVelX2 = (secondBall.velocity.x * (secondBall.mass - firstBall.mass) + (2 * firstBall.mass * firstBall.velocity.x)) / (firstBall.mass + secondBall.mass);
        let newVelY2 = (secondBall.velocity.y * (secondBall.mass - firstBall.mass) + (2 * firstBall.mass * firstBall.velocity.y)) / (firstBall.mass + secondBall.mass);
        firstBall.velocity = createVector(newVelX1, newVelY1)
        secondBall.velocity = createVector(newVelX2, newVelY2)
        firstBall.position.x = firstBall.position.x + newVelX1;
        firstBall.position.y = firstBall.position.y + newVelY1;
        secondBall.position.x = secondBall.position.x + newVelX2;
        secondBall.position.y = secondBall.position.y + newVelY2;
    }
}