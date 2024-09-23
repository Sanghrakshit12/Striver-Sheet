function convertToMinutes(time, isDeparture = false) {
    let hours = Math.floor(time / 100);
    let minutes = time % 100;
    let totalMinutes = hours * 60 + minutes;
    
    if (isDeparture && totalMinutes < 300) {
        totalMinutes += 1440; 
    }
    
    return totalMinutes;
}

function findPlatform(arr, dep) {
    let order = [];
    let n = arr.length;
    
    for (let i = 0; i < n; i++) {
        order.push([ convertToMinutes(arr[i]), 0 ]);        
        order.push([ convertToMinutes(dep[i], true), 1 ]);   
    }
    
    order.sort(function(a, b) {
        if (a[0] == b[0]) return a[1] - b[1];
        return a[0] - b[0];
    });
    
    let result = 1;
    let plat_needed = 0;
    
    for (let it = 0; it < order.length; it++) {
        if (order[it][1] == 0)
            plat_needed++; 
        else
            plat_needed--;
        
        if (plat_needed > result) result = plat_needed;
    }
    
    return result;
}

function main() {
    const arr = [900,920,950,1000,1100,1800];
    const dep = [930,1200,1120,1130,1900,2000];
    
    console.log("Minimum number of Platforms required:", findPlatform(arr, dep));
}

main();
