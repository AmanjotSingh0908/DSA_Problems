    //Function to check if brackets are balanced or not.
    ispar(x)
    {
        const stack=[]
        for(let i=0; i<x.length; i++){
            let char = x[i];
            if(char == '(' || char=='[' || char=='{'){
                stack.push(char)
            } else {
                let top = stack.pop()
                if((char==')' && top != '(') || (char === ']' && top != '[') || (char ==='}' && top !='{')){
                    return false
                }
            }
        }
        if(stack.length==0){
            return true;
        }
        return false;
    }