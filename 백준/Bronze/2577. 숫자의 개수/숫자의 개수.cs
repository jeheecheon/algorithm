int first;
int second;
int third;

if (Int32.TryParse(Console.ReadLine(), out first) == false) {
    throw new Exception("Failed to get the first input");
}

if (Int32.TryParse(Console.ReadLine(), out second) == false) {
    throw new Exception("Failed to get the second input");
}

if (Int32.TryParse(Console.ReadLine(), out third) == false) {
    throw new Exception("Failed to get the third input");
}

long calc_result = first * second * third;

string string_result = calc_result.ToString();

Dictionary<int, int> cnt = new Dictionary<int, int>();

for (int idx = 0; idx < 10; ++idx) {
    cnt[idx] = 0; 
}

for (int idx = 0; idx < string_result.Length; ++idx)
{
    int temp = string_result[idx] - '0';
    cnt[temp]++;
}

for (int idx = 0; idx < 10; ++idx) {
    Console.WriteLine($"{cnt[idx]}");
}