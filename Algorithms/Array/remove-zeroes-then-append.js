/**
 * Removed zeroes from an array then append them to the same array
 *
 * @example <caption>An array with 0 before numbers 1-9</caption>
 * // test becomes: (18) [1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0]
 * test = [0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9];
 * removeZeroesThenAppend(test);
 *
 * @param {*} array
 */
function removeZeroesThenAppend(array) {
  const firstInstance = array.indexOf(0);

  // ~x basically turns it into truthy/falsy via -1 == false, vs everything else
  // -via Kyle Simpson
  if (~firstInstance) {
    const lastInstance = array.lastIndexOf(0);

    // If there's a last instance and it's not the first, i.e. only:
    if (~lastInstance && lastInstance !== firstInstance) {
      // Run the first iteration manually since we don't need the conditional,
      // but only if 0 isn't the last thing in the array to begin with. There
      // would be no observable way to tell the last item had changed from 0, to
      // nothing, then back to 0 again.
      if (lastInstance < array.length - 1) {
        array.splice(lastInstance, 1);
        array.push(0);
      }

      // Loop between the first and last instances of 0 to hunt, murder, and
      // resurrect the remaining 0s, if any.
      for (let i = lastInstance - 1; i >= firstInstance; --i) {
        if (array[i] === 0) {
          // If whoever is looking for `delete array[i]`, then use that here
          // instead. Otherwise note that it would delete the value stored in
          // that position, but that key would remain in place and the length
          // of the array would remain unchanged. Ergo we use splice instead.
          array.splice(i, 1);
          array.push(0);
        }
      }
    } else {
      // Handle the only 0 in the array if it's not the only thing in the array
      if (array.length > 1) {
        array.splice(firstInstance, 1);
        array.push(0);
      }
    }
  }
}
