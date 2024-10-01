/**
 * @param {string} str
 * @return {number}
 */
function value(r) {
  if (r === 'I') return 1;
  if (r === 'V') return 5;
  if (r === 'X') return 10;
  if (r === 'L') return 50;
  if (r === 'C') return 100;
  if (r === 'D') return 500;
  if (r === 'M') return 1000;
  return -1;
}

var romanToInt = function(s) {

  let res = 0;
  for (let i = 0; i < s.length; i++) {
    let s1 = value(s[i]);
    if (i + 1 < s.length) {
    
      let s2 = value(s[i + 1]);
      if (s1 >= s2) {
        res += s1;
      } else {
        res += (s2 - s1);
        i++;
      }
    } else {
      res += s1;
    }
  }
  return res;

};
