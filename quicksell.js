


function countStudents(arr, pages) {
    var n = arr.length; 
    var students = 1;
    var pagesStudent = 0;
    for (var i = 0; i < n; i++) {
        if (pagesStudent + arr[i] <= pages) {
            pagesStudent += arr[i];
        } else {
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

function findPages(arr, n, m) {
    if (m > n) return -1;
    var low = Math.max(...arr);
    var high = arr.reduce((a, b) => a + b, 0);
    while (low <= high) {
        var mid = Math.floor((low + high) / 2);
        var students = countStudents(arr, mid);
        if (students > m) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

var arr = [1,2,3,3,3,3,5,6,3];
var n = 2;
var m = 2;
var ans = findPages(arr, n, m);
console.log("The answer is: " + ans);

