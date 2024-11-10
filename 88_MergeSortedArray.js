

var merge = function(nums1, m, nums2, n) {
    
    let i = m - 1;
    let j = n - 1;
    let last = nums1.length - 1;

    while (last >= 0)
    {
        if(i < 0)
        {
            nums1[last--] = nums2[j--];
        }
        else if(j<0)
        {
            nums1[last--] = nums1[i--];
        }
        else if(nums1[i] > nums2[j])
        {
            nums1[last--] = nums1[i--];
        }
        else
        {
            nums1[last--] = nums2[j--];
        }
    }
    return nums1;
};

let main = function()
{
    let  nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3;
    console.log(merge(nums1,m,nums2,n));
}

main(); 