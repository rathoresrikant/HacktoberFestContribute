export function areTwoStringsAnagrams(firstString, secondString) {
    if (typeof firstString !== 'string' || typeof secondString !== 'string') throw new Error('isAnagram requires two strings to be passed.')

    // Normalize the two strings
    const normalizedFirstString = firstString.replace(/[^A-Za-z]+/g, '').toLowerCase();
    const normalizedSecondString = secondString.replace(/[^A-Za-z]+/g, '').toLowerCase();

    let c = [];
    // Cache length for optimal performance
    let firstStringLength = normalizedFirstString.length;
    let secondStringLength = normalizedSecondString.length

    // Return false if the two aren't the same length, saves constly calculation in extreme cases
    if (firstStringLength !== secondStringLength) return false

    for (let i = 0; i < firstStringLength; i++) {
        let index = normalizedFirstString.charCodeAt(i) - 97;
        c[index] = (c[index] || 0) + 1;
    }

    for (let i = 0; i < secondStringLength; i++) {
        let index = normalizedSecondString.charCodeAt(i) - 97;
        if (!c[index]) { return false; }
        else { c[index]--; }
    }

    return true;
}