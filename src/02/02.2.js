const fs = require('fs');

const evaluateList = (n) => {
  const differences = [];
  n.forEach((x, i) => {
    if (i + 1 < n.length) {
      differences.push(x - n[i + 1]);
    }
  });
  const asc = differences.every((x) => x >= 1 && x <= 3);
  const dsc = differences.every((x) => x <= -1 && x >= -3);
  return asc || dsc;
};

const data = fs
  .readFileSync('./input1.txt', 'utf8')
  .split('\n')
  .filter(Boolean)
  .map((l) => l.split(' ').map((x) => +x));

let agg = 0;
data.forEach((l) => {
  const fp = evaluateList(l);
  if (fp) {
    agg += 1;
    return;
  }

  for (let i = 0; i < l.length; i++) {
    const sp = evaluateList([...l.slice(0, i), ...l.slice(i + 1)]);
    if (sp) {
      agg += 1;
      return;
    }
  }
});

console.log(agg);
