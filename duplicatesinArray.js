function duplicates(a, n) {
    let result = []
    a.sort((x, y) => x-y )
    // your code here
    for(let i=0; i<n-1; i++){
        if(a[i] == a[i+1]){
            if(!result.includes(a[i])){
            result.push(a[i])
            }
        }
    }
    return result;
}

let myarray = [1,23,1,43,21,23]
answer = duplicates(myarray, 6)
console.log(answer)