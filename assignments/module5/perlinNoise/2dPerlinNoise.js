let inc = 0.01;

function setup() {
    createCanvas(400, 400);
    pixelDensity(1);
}

function draw() {
    loadPixels();
    background(51);
    
    let yoff = 0;
    for (let x = 0; x < width; x++) {
        let xoff = 0;
        for (let y = 0; y < height; y++) {
            let index = (x + y * width) * 4;
            let r = noise(xoff, yoff) * 255;
            
            noiseDetail(4, 0.5); // 4 is default detail level (nr of octaves), 0.5 is default halving factor

            pixels[index + 0] = r; // R
            pixels[index + 1] = r;   // G
            pixels[index + 2] = r;   // B
            pixels[index + 3] = 255; // A
            xoff += inc;
        }
        yoff += inc;
    }

    updatePixels();

    // noLoop();
}