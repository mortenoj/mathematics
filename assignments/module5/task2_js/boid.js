class Boid {
    constructor() {
        this.position = createVector(random(width), random(height));
        this.velocity = p5.Vector.random2D();
        this.velocity.setMag(random(2, 4))
        this.acceleration = createVector();
        this.maxForce = 1; // How much a boid can change it's steering vector
        this.maxSpeed = 4;
    }

    // make boids reapear in the other side of the canvas on edges
    edgeIntersection() {
        if (this.position.x > width) {
            this.position.x = 0;
        } else if (this.position.x < 0) {
            this.position.x = width;
        }
        if (this.position.y > height) {
            this.position.y = 0;
        } else if (this.position.y < 0) {
            this.position.y = height;
        }
    }

    /**
     * Definition: Steer to avoid crowding local flockmates
     *      Say we have one boid steering towards another
     * 
     *      We then want to steer in the oposite direction
     * 
     *      If there then are multiple boids within a threshold
     * 
     *      We want to steer clear of them too
     * 
     *      The desired direction is the average of all the oposite directions
     *      of all the other boids within a threshold.
     * 
     *      The magnitude/distance of the other boid is also relevant to the
     *      magnitude of the new oposite direction of that boid
     * @param {Boid} boids flock
     */
    separation(boids) {
        let perceptionRadius = 50; // Max radius to evaluate boids
        let steering = createVector(); // Steering vector
        let total = 0;
        boids.map((boid) => {
            // Distance between this point and other point
            let distance = dist(this.position.x, this.position.y, boid.position.x, boid.position.y);
            // Other is not this and other is within perceptionRadius
            if (boid != this && distance < perceptionRadius) {
                let diff = p5.Vector.sub(this.position, boid.position);
                diff.div(distance * distance); // Invertionally proportionate to the distance
                steering.add(diff);
                total++;
            }
        })
        if (total > 0) {
            steering.div(total); // Average it 
            steering.setMag(this.maxSpeed); // Set it to max speed
            steering.sub(this.velocity); // Sub out the velocity
            steering.limit(this.maxForce); // Limit the change of direction to maxForce
        }
        return steering;
    }

    /**
     * Steer towards the average position of the flock within a radius
     * Definition: Steer to move toward the average position of local flockmates
     * @param {Boid} boids flock
     */
    cohesion(boids) {
        let perceptionRadius = 100; // Max radius to evaluate boids
        let steering = createVector(); // Steering vector
        let total = 0;
        boids.map((boid) => {
            // Distance between this point and other point
            let distance = dist(this.position.x, this.position.y, boid.position.x, boid.position.y);
            // Other is not this and other is within perceptionRadius
            if (boid != this && distance < perceptionRadius) {
                steering.add(boid.position);
                total++;
            }
        })
        if (total > 0) {
            // calculate the average position in the steering vector
            steering.div(total); // Steering allignment is avg of others position
            // Steer = desiredPosition - position
            steering.sub(this.position);
            steering.setMag(this.maxSpeed);
            steering.sub(this.velocity);
            steering.limit(this.maxForce);        
        }
        return steering;
    }

    /**
     * Aligns one boid based on the average velocity of other boids within a radius
     * Definition: Steer towards the average heading of local flockmates
     * @param {Boid} boids flock
     */
    align(boids) {
        let perceptionRadius = 50; // Max radius to evaluate boids
        let steering = createVector(); // Steering vector
        let total = 0;
        boids.map((boid) => {
            // Distance between this point and other point
            let distance = dist(this.position.x, this.position.y, boid.position.x, boid.position.y);
            // Other is not this and other is within perceptionRadius
            if (boid != this && distance < perceptionRadius) {
                steering.add(boid.velocity);
                total++;
            }
        })
        if (total > 0) {
            // calculate the average velocity in the steering vector
            steering.div(total); // Steering allignment is avg of others velocity
            // We don't want to assign this.velocity to the average velocity
            // We want to use velocity to steer the boid TOWARDS the avg velocity
            // Steer = desiredVelocity - velocity
            steering.setMag(this.maxSpeed);
            steering.sub(this.velocity);
            steering.limit(this.maxForce);        
        }
        return steering;
    }

    flock(boids) {
        // We have three forces: allignment, cohesion and separation
        // Use force accumilation to accumulate them together = force1 + force2
        // If two or more forces act on an object, the force on the object is the sum of the forces acting on it
        // acceleration = mass * force -> mass = 1
        let alignment = this.align(boids);
        let cohesion = this.cohesion(boids);
        let separation = this.separation(boids);

        separation.mult(separationLvl.value());
        alignment.mult(alignLvl.value());
        cohesion.mult(cohesionLvl.value());

        this.acceleration.add(alignment); 
        this.acceleration.add(cohesion);
        this.acceleration.add(separation);
    }


    update() {
        this.position.add(this.velocity);
        this.velocity.add(this.acceleration);
        this.velocity.limit(this.maxSpeed);
        this.acceleration.mult(0);
    }

    show() {
        strokeWeight(8);
        stroke(255);
        point(this.position.x, this.position.y);
    }
}