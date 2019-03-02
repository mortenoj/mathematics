'use strict';


let c = document.getElementById('canvas');
let ctx = c.getContext('2d');

// ctx.moveTo(0,0);
// ctx.lineTo(200,200);
// ctx.stroke();

function getBodyHeight() {
  let B = document.body,
      H = document.documentElement,
      height

  if (typeof document.height !== 'undefined') {
      height = document.height // For webkit browsers
  } else {
      height = Math.max(
        B.scrollHeight,
        B.offsetHeight,
        H.clientHeight,
        H.scrollHeight,
        H.offsetHeight
      );
  }
  return height;
}

let canvasHeight = getBodyHeight();

c.height = canvasHeight;
c.width = canvasHeight;

let x = 0;
let y = 0;

let rectWidth = c.width/32;
let rectHeight = c.height/32;

for (let i = 0; i < 32; i++) {
  for (let j = 0; j < 32; j++) {
    ctx.rect(x, y, rectWidth, rectHeight);
    ctx.stroke();

    y += rectHeight;
    x += rectWidth;
  }
}
