"use strict";

const throwDice = throws => {
  let dice = [0,0,0,0,0,0];
  for(let i = 0; i < throws; ++i)
    dice[Math.floor(Math.random()*6)] += 1;
  return dice;
}
const indexOfMax = arr =>  {
    if (arr.length === 0)
        return -1;
    let max = arr[0];
    let maxIndex = 0;
    for (let i = 1; i < arr.length; i++) {
        if (arr[i] > max) {
            maxIndex = i;
            max = arr[i];
        }
    }
    return maxIndex;
}
const yahtzee = dices => (Math.max.apply(Math, dices) === 5);
const findAndRethrow = (dices, times) => {
  let dice = [0,0,0,0,0,0];
  let index = indexOfMax(dices);
  dice[index] = dices[index];
  if(yahtzee(dice))
    return true;
  if(times > 0) {
    let diceRethrow = throwDice(5 - dice[index]);
    diceRethrow.map((value, index) => dice[index] += value);
    return findAndRethrow(dice, times - 1);
  }
  return false;
}



let start = +new Date;
let simulatedTurns = 1000000;
for(let j = 0; j < 100; ++j) {
  let count = 0;
  let i = 0;

  while(i < simulatedTurns) {
    if(findAndRethrow(throwDice(5), j))
      count += 1;
    i +=1
  }
  console.log(count / (simulatedTurns / 100))
  if(count /(simulatedTurns / 100) > 90) {
    console.log("Hits 50% after ", j+1, " throws");
    break;
  }
}

console.log("duration: ", (+new Date - start)/1000, "S");
