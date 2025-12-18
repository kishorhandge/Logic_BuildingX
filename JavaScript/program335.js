function Display(no)
{
    console.log("JAY GANESH..."+no);
    return ++no;
}

function main()
{   
    let iRet = 0;

    iRet = Display(11);

    console.log("return value is :"+iRet);
}

main()