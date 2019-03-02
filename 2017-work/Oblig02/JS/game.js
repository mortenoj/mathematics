'use strict';

const windowX = 512;
const windowY = 512;
const dotRad = 16.0;
const numDots = 512/32;

let colours = ['red', 'white', 'blue', 'green', 'cyan', 'magenta', 'yellow', 'black'];


let canvas = document.querySelector(".canvas");
let ctx = canvas.getContext('2d');

// function drawDots() {
//   for(let i=0; i<numDots; ++i) {
//     for(let j=0; j<numDots; ++j) {
//       ctx.beginPath();
//       ctx.arc(30 + (i * 35),40 + (j * 35), dotRad, 0,2*Math.PI);
//       ctx.fillStyle = colours[Math.floor(Math.random() * 7)];
//       ctx.fill();
//       ctx.stroke();
//     }
//   }
// }
//
// drawDots();


  for(let i = 0; i < numDots; ++i) {
    let div = document.createElement('div', {
      'id': i,
      'class': i,
      'height': '20px',
      'width': '20px'
    });
    body.appendChild(div);
    div.style.backgroundColor = 'red';
  }
}
