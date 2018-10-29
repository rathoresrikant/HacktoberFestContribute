/**
 * Switch a string's lowercase characters to uppercase and uppercase characters
 * to lowercase.
 *
 * This method uses rather simple RegEx instead of any kind of loop.
 *
 * In JavaScript, string values are immutable, so no matter what, whether we
 * convert to an array or not, we're still going to end up with a new string.
 * Especially if we're making no presumptions about the string being formatted,
 * why not then use RegEx? There's also a slight attempt here to respect locale.
 *
 * @example <caption>Default example</caption>
 * // returns "1 REAllY MiXED STRiNG!"
 * switchCase();
 *
 * @param {string} [string="1 reaLLy mIxed strIng!"] - String to be formatted
 * @param {object} locale - Locale settings for RegEx search and String methods
 * @param {string} [locale.locale="en-US"] - Locale to be used in String methods
 * @param {string} [locale.localeLowerRange="a-z"] - RegEx string for your locale's lowercase characters (to go within square brackets)
 * @param {string} [locale.localeUpperRange="A-Z"] - RegEx string for your locale's uppercase characters (to go within square brackets)
 * @returns {string} New, formatted string
 */
function switchCase(
  string = "1 reaLLy mIxed strIng!",
  { locale = "en-US", localeLowerRange = "a-z", localeUpperRange = "A-Z" } = {}
) {
  // Default: /([a-z])|(A-Z)/g
  // We match each case individually so we can easily target them in the
  // replacement function below.
  const lowerAndUpperRegex = new RegExp(
    `([${localeLowerRange}])|([${localeUpperRange}])`,
    "g"
  );

  return string.replace(
    lowerAndUpperRegex,
    (character, lowerCase, upperCase) => {
      if (lowerCase) {
        return lowerCase.toLocaleUpperCase(locale);
      } else if (upperCase) {
        return upperCase.toLocaleLowerCase(locale);
      }

      // leave non-alphabetical characters alone
      return character;
    }
  );
}
