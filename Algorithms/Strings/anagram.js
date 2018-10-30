function stringInTheMirror(str) {
  if (str === '') {
    throw new Error('The string is empty')
  } else if (Object.prototype.toString.call(str) === '[object String]') {
    str = str.split('')
  }

  var len  = str.length
  var firstCharPos = 0
  var lastCharPos = len - 1

  for (var i = 1; i < len / 2; i++) {
    var temp = str[0]
    str[firstCharPos] = str[lastCharPos]
    str[lastCharPos] = temp
  }

  return str.join('').toLowerCase()
}

function anamgram(stringOne, stringTwo) {
  if (stringTwo === undefined) {
    return stringOne === stringInTheMirror(stringOne)
  }

  return stringOne === stringInTheMirror(stringTwo)
}

// https://en.wikivoyage.org/wiki/Anina

console.log(anamgram('Anina'))