import fs from 'node:fs';

let l1: number[] = [];
let l2: number[] = [];

fs.readFileSync('./input1.txt', 'utf8')
  .split('\n')
  .filter(Boolean)
  .map((l) =>
    l
      .replace('   ', ' ')
      .split(' ')
      .forEach((l, i) => {
        i === 0 ? l1.push(+l) : l2.push(+l);
      }),
  );

l1 = l1.sort();
l2 = l2.sort();

let agg = 0;

for (let i = 0; i < l1.length; i++) {
  // @ts-ignore
  agg += Math.abs(l1[i] - l2[i]);
}
console.log(l1);
console.log(l2);
console.log(agg);
console.log('warra warra');
