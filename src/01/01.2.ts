import fs from 'node:fs';

let l1: number[] = [];
let l2: { [key: string]: number } = {};

fs.readFileSync('./input1.txt', 'utf8')
  .split('\n')
  .filter(Boolean)
  .map((l) =>
    l
      .replace('   ', ' ')
      .split(' ')
      .forEach((l, i) => {
        if (i === 0) {
          l1.push(+l);
        } else {
          if (l2[l]) {
            l2[l] += 1;
          } else {
            l2[l] = 1;
          }
        }
      }),
  );

let agg = 0;

for (let i = 0; i < l1.length; i++) {
  // @ts-ignore
  agg += l1[i] * (l2[l1[i]] || 0);
}
console.log(l1);
console.log(l2);
console.log(agg);
console.log('warra warra');
