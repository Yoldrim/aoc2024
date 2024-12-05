const fs = require('fs');

let [section1, section2] = fs
  .readFileSync('./src/05/input1.txt', 'utf8')
  .split('\n\n')
  .map((x) => x.split('\n').filter(Boolean));

section1 = section1.map((x) => x.split('|').map((y) => +y));
section2 = section2.map((x) => x.split(',').map((y) => +y));

const sort = (update) =>
  update.sort((a, b) => {
    for (const rule of section1) {
      if (rule[0] === a && rule[1] === b) return 1;
      if (rule[0] === b && rule[1] === a) return -1;
    }
    return 0;
  });

const agg = section2.reduce((acc, update) => {
  const isValid = update.every((page, pageIndex) => {
    return section1.every((rule) => {
      if (rule[1] !== page) return true;
      const index = update.indexOf(rule[0]);
      return index === -1 || index < pageIndex;
    });
  });

  return isValid ? acc : acc + sort(update)[(update.length - 1) / 2];
}, 0);

console.log(agg);
