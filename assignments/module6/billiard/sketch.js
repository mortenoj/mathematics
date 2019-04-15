let board;

function setup() {
    createCanvas(640, 360);
    board = new Board();
    
    // White initial ball
    board.addBall(createVector(20, height/2), true);

    // Other balls
    for (let i = 0; i < 10; i++) {
        board.addBall(createVector(random(width), random(height)));
    }
}

function draw() {
    background(51);

    board.update();
    board.show();
}