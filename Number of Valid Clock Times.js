/**
 * @param {string} time
 * @return {number}
 */
var countTime = function(time) {

    const [hour, minute] = time.split(":");

    // Determine valid hour combinations
    let validHours = 0;
    if (hour[0] === '2' && hour[1] === '?') {
        validHours = 4; // "20", "21", "22", "23"
    } else if (hour[0] === '?' && hour[1] === '?') {
        validHours = 24; // "00" to "23" (24 possibilities)
    } else if (hour[0] === '?') {
        const secondDigit = parseInt(hour[1]);
        if (secondDigit >= 0 && secondDigit <= 3) {
            validHours = 3; // "00" to "03"
        } else {
            validHours = 2; // "10" to "19"
        }
    } else if (hour[1] === '?') {
        const firstDigit = parseInt(hour[0]);
        if (firstDigit === 2) {
            validHours = 4; // "20" to "23"
        } else {
            validHours = 10; // "00" to "09" and "10" to "19"
        }
    } else {
        validHours = 1; // One valid hour (already given)
    }

    // Determine valid minute combinations
    let validMinutes = 0;
    if (minute[0] === '?' && minute[1] === '?') {
        validMinutes = 60; // "00" to "59" (60 possibilities)
    } else if (minute[0] === '?') {
        validMinutes = 6; // "00" to "09", "10" to "19", ..., "50" to "59"
    } else if (minute[1] === '?') {
        validMinutes = 10; // "00", "01", ..., "09"
    } else {
        validMinutes = 1; // One valid minute (already given)
    }

    // Return the total number of valid times
    return validHours * validMinutes;


};
