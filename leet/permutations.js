var permute = function(nums, perm=[], perms=[]) {
    if (!nums.length) perms.push([...perm]);

    for (let i = 0; i < nums.length; ++i) {
        const newNums = nums.filter((n, index) => index !== i);
        perm.push(nums[i]);
        permute(newNums, perm, perms);
        perm.pop();
    }
    return perms;
}