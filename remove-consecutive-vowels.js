const vowels = ["a", "e", "i", "o", "u"];
const word = 'beautiful';

function isVowel(letter){
  return vowels.includes(letter.toLowerCase()) ? true :  false;
}

function removeVowels(word) {
  if(word.length === 0) {
    return console.log('no word provided');
  }
  
  if(!isVowel(word[0]) || isVowel(word[0]) && !isVowel(word[1]) ){
      console.log(word[0]);
  }
  
  for(let i=1; i<word.length; i++ ) {
    if( (isVowel(word[i]) && !isVowel(word[i-1]) && !isVowel(word[i+1]))|| (!isVowel(word[i]))) {
       console.log(word[i]);
    }
  }
}

removeVowels(word);
