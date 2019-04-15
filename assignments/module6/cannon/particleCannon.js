class ParticleCannon {
    constructor(position) {
        this.origin = position.copy();
        this.particles = [];
    };
    
    addParticle(target) {
      this.particles.push(new Particle(this.origin, target));
    };

    run() {
      for (let i = this.particles.length-1; i >= 0; i--) {
        let p = this.particles[i];
        p.run();
        if (p.isDead()) {
          this.particles.splice(i, 1);
        }
      }
    };
}