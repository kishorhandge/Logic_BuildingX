
function Factorial(no)
{
    let iCnt = 0;

    let iFact = 1;

    for(iCnt = no;iCnt>=1;iCnt--)
    {
        iFact = iFact*iCnt;
    }

    return iFact;
}

function main()
{   
   let iValue = 20;

   let iRet = 0;

   iRet = Factorial(iValue);

   console.log("Factorial of ${iValue} is ${iRet}");

}

main(); 