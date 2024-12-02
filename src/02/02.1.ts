import fs from 'node:fs';

// @ts-ignore
let agg = 0;
const data = fs
  .readFileSync('./input1.txt', 'utf8')
  .split('\n')
  .filter(Boolean)
  .map((l) => l.split(' ').map((x) => +x));

data.forEach((l) => {
  let safe = true,
    dscSafe = true,
    ascSafe = true;
  for (let j = 0; j < l.length - 1; j++) {
    // @ts-ignore
    const n = Math.abs(l[j] - l[j + 1]);
    console.log(l[j], l[j + 1], n);
    // @ts-ignore
    if (l[j] > l[j + 1]) {
      dscSafe = false;
    }

    // @ts-ignore
    if (l[j] < l[j + 1]) {
      ascSafe = false;
    }

    if (n < 1 || n > 3) {
      safe = false;
    }
  }
  console.log(`safe: ${safe}`);
  if (safe && (dscSafe || ascSafe)) {
    agg += 1;
  }
});

console.log(data);
console.log(agg);
