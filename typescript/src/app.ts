let phonepad: number[][] = [
 [7, 8, 9], //0
 [2, 4, 5], //1
 [1, 3, 4, 5, 6], //2
 [2, 5, 6], //3
 [1, 2, 5, 7, 8], //4
 [1, 2, 3, 4, 6, 7, 8, 9], //5
 [2, 3, 5, 8, 9], //6
 [4, 5, 8, 0], //7
 [4, 5, 6, 7, 9, 0], //8
 [5, 6, 8, 0], //9
];

let count = 0;  
function solvePuzzle(chosenNumber: number, group: Array<number>, canCross: boolean = true): boolean {
  group.push(chosenNumber);
  
  // prevent digits crossing
  if (!canCross && digitsCross(group))
    return false;

  // base case
  if (group.length == 9)
  {
    return isSolution(group);
  }
  // continue until we have 9 digits
  else
  {
    for(var num of phonepad[chosenNumber])
    {
      var solution = nextDigit(num, group, canCross);
      // cease recursion if we found our solution
      if (solution)
        return solution;
    }
  }
}

function digitsCross(digits: Array<number>): boolean
{
  if (digits.length < 4)
    return false;
  const length = digits.length;

  const firstInt: number = digits[length - 1];
  const secondInt: number = digits[length - 2];
  const thirdInt: number = digits[length - 3];
  const fourthInt: number = digits[length - 4];

  const cross: boolean = firstInt + secondInt === thirdInt + fourthInt;
  return cross;
}

function nextDigit(num: number, group: Array<number>, canCross: boolean): boolean
{
  if (group.indexOf(num) === -1)
  {
    var solution: boolean = solvePuzzle(num, group, canCross);
    if (solution)
      return solution;
    else
    {
      group.pop();
      return false;      
    }
  }
}

function isSolution(digits: Array<number>): boolean
{
  var first = new Number(`${digits[0]}${digits[1]}${digits[2]}`).valueOf();
  var secon = new Number(`${digits[3]}${digits[4]}${digits[5]}`).valueOf();
  var third = new Number(`${digits[6]}${digits[7]}${digits[8]}`).valueOf();

  var isSolution = first + secon === third;
  if (isSolution)
  {
    console.log(`${first} + ${secon} == ${third} | ${first + secon === third} | `, digits);
    return true;
  }
  else
  {
    return false;
  }
}

for(var i = 0; i < phonepad.length; i++)
{
  solvePuzzle(i, [], true);
}