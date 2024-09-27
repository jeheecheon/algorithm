using (StreamReader sr = new StreamReader(new BufferedStream(Console.OpenStandardInput())))
using (StreamWriter sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()))) {
    int[] input = sr.ReadLine()!.Split().Select(int.Parse).ToArray();
    int N = input[0], M = input[1];

    Dictionary<string, int> nameNum = new();
    Dictionary<int, string> numName = new();

    for (int i = 1; i <= N; ++i) {
        string name = sr.ReadLine()!;
        nameNum.Add(name, i);
        numName.Add(i, name);
    }

    for (int i = 0; i < M; ++i) {
        string query = sr.ReadLine()!;
        if (int.TryParse(query, out int num))
            sw.WriteLine(numName[num]);
        else sw.WriteLine(nameNum[query]);
    }
}
