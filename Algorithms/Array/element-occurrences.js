/**
 * Find how many times an element occurs within a sorted array.
 *
 * @example
 * // returns 4
 * totalOccurrences([0,0,1,2,2,2,3,3,3,3,5,6,9,10], 3);
 *
 * @example
 * // returns 0
 * totalOccurrences([0,0,1,2,2,2,3,3,3,3,5,6,9,10], 7);
 *
 * @param {Array} array - Sorted array of elements
 * @param {*} element - Element we're looking to find within array and count occurrences of.
 * @returns {number} - Total amount of times element was found within array.
 */
function totalOccurrences(array, element) {
  const firstInstance = array.indexOf(element);

  let instancesFound = 0;

  // ~x basically turns it into truthy/falsy via -1 == false, vs everything else
  // -via Kyle Simpson
  if (~firstInstance) {
    // If there are few or no repetitions of element, we can iterate through the
    // the array to find the remaining occurrences if any. Otherwise, see
    // alternative commented out below.
    //
    // Also, we start with firstInstance instead of firstInstance+1, so we don't
    // have to check if it's the last item in the array to determine whether or
    // not to loop to begin with. This keeps it simple.
    for (let i = firstInstance, end = array.length; i < end; ++i) {
      if (array[i] === element) {
        ++instancesFound;
      } else {
        // The moment we no longer find a match, quit looping.
        break;
      }
    }

    // Alternatively, if repetitions of element occupy most of the array we
    // could use lastIndexOf instead of the for loop, e.g.:
    // const lastInstance = array.lastIndexOf(element);
    // instancesFound = 1 + (lastInstance - firstInstance); // the 1 represents firstInstance
  }

  return instancesFound;
}
