int[] input = Console.ReadLine()!.Split().Select(int.Parse).ToArray();
long[] trees = Console.ReadLine()!.Split().Select(long.Parse).ToArray();
Console.Write(func(0, trees.Max()));

long func(long min, long max) {
    long mid = (max + min) / 2;
    long woodTaken = trees.Select(t => Math.Max(t - mid, 0)).Sum();

    if (mid == min) 
        return trees.Select(t => Math.Max(t - max, 0)).Sum() >= input[1] ? max : mid;
    else if (woodTaken >= input[1]) 
        return func(mid, max);
    else
        return func(min, mid - 1);
}