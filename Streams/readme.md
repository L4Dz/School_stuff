# Complete Guide to fstream and sstream in C++

## Key Principle: **Never Mix Reading Methods on the Same Stream**

The most important rule: Don't mix `getline()` with `>>` operator on the same stream in the same loop!

## 1. Reading with `>>` Operator

### When to use:
- Reading **individual tokens** (words, numbers)
- When you want to **skip whitespace automatically**
- When data format is predictable

### How it works:
```cpp
ifstream file("data.txt");
string word;
int number;

// Reads word by word, skipping all whitespace
while (file >> word) {
    cout << "Word: " << word << endl;
}

// Reads numbers, skipping whitespace
while (file >> number) {
    cout << "Number: " << number << endl;
}
```

### Example file:
```
hello    world
123   456
```
Output: "hello", "world", fails on "123" (trying to read string)

## 2. Reading with `getline()`

### When to use:
- Reading **entire lines**
- When you need to **preserve line structure**
- When lines have different formats
- When you need to process each line differently

### How it works:
```cpp
ifstream file("data.txt");
string line;

while (getline(file, line)) {
    cout << "Line: '" << line << "'" << endl;
}
```

### Example file:
```
Alice 25 Engineer
Bob 30 Doctor
```
Output:
- Line: 'Alice 25 Engineer'
- Line: 'Bob 30 Doctor'

## 3. The Problem: Mixing `getline()` and `>>`

### ❌ WRONG - What you did:
```cpp
while (getline(ifs, line)) {
    ifs >> begin;  // This reads from the NEXT line!
    // Process line...
}
```

### Why it fails:
1. `getline()` reads "Alice 25 30 35" and moves to next line
2. `ifs >> begin` reads "Bob" from the NEXT line
3. You process "Alice 25 30 35" but think the name is "Bob"

## 4. The Solution: Use `stringstream` for Line Processing

### ✅ CORRECT Approach:
```cpp
string line;
while (getline(file, line)) {
    istringstream iss(line);  // Create stream from current line
    
    string name;
    iss >> name;  // Read from the line, not the file
    
    int age;
    while (iss >> age) {  // Read remaining numbers from the line
        // Process each age
    }
}
```

## 5. Complete Examples

### Example 1: Reading structured data
```cpp
// File: "students.txt"
// Alice 85 92 78
// Bob 91 88 95

void processGrades(const string& filename) {
    ifstream file(filename);
    string line;
    
    while (getline(file, line)) {
        istringstream iss(line);
        string name;
        iss >> name;
        
        vector<int> grades;
        int grade;
        while (iss >> grade) {
            grades.push_back(grade);
        }
        
        // Calculate average
        double avg = 0;
        for (int g : grades) avg += g;
        avg /= grades.size();
        
        cout << name << ": " << avg << endl;
    }
}
```

### Example 2: Reading simple word list
```cpp
// File: "words.txt"
// apple
// banana
// cherry

void readWords(const string& filename) {
    ifstream file(filename);
    string word;
    
    // Simple: one word per operation
    while (file >> word) {
        cout << "Word: " << word << endl;
    }
}
```

### Example 3: Mixed data types
```cpp
// File: "mixed.txt"
// John 25 1.75 Engineer
// Mary 30 1.68 Doctor

void readPeople(const string& filename) {
    ifstream file(filename);
    string line;
    
    while (getline(file, line)) {
        istringstream iss(line);
        
        string name, job;
        int age;
        double height;
        
        iss >> name >> age >> height >> job;
        
        cout << name << " is " << age << " years old" << endl;
    }
}
```

## 6. Decision Tree: Which Method to Use?

```
Do you need to process data line by line?
├── YES → Use getline() + stringstream
│   ├── Different format per line? → getline() + stringstream
│   ├── Need to preserve line structure? → getline() + stringstream
│   └── Mixed data types per line? → getline() + stringstream
│
└── NO → Use >> operator directly
    ├── All same data type? → while(file >> data)
    ├── Simple word-by-word? → while(file >> word)
    └── Known format? → file >> a >> b >> c
```

## 7. Common Patterns

### Pattern 1: CSV-like data
```cpp
// name,age,salary
string line;
while (getline(file, line)) {
    istringstream iss(line);
    string name, ageStr, salaryStr;
    
    getline(iss, name, ',');
    getline(iss, ageStr, ',');
    getline(iss, salaryStr, ',');
    
    int age = stoi(ageStr);
    double salary = stod(salaryStr);
}
```

### Pattern 2: Variable number of items per line
```cpp
string line;
while (getline(file, line)) {
    istringstream iss(line);
    string first;
    iss >> first;
    
    vector<double> numbers;
    double num;
    while (iss >> num) {  // Read until end of line
        numbers.push_back(num);
    }
}
```

### Pattern 3: Fixed format
```cpp
// When you know exactly what's on each line
string name;
int age;
double salary;

while (file >> name >> age >> salary) {
    // Process each person
}
```

## 8. Key Takeaways

1. **One method per stream context**: Don't mix `getline()` and `>>` on the same stream
2. **Use `stringstream` for complex line parsing**: When you need both line structure and token parsing
3. **`getline()` preserves structure**: Use when line boundaries matter
4. **`>>` skips whitespace**: Use for simple token reading
5. **Always check stream state**: Use `if (!file)` or `if (!getline(file, line))`

## 9. Your Original Mistakes Summary

1. **Mixed reading methods**: `getline()` + `ifs >>` on same stream
2. **Wrong scope**: Reading from file instead of parsing the line
3. **Missing sorting**: Calculated median on unsorted data
4. **Variable scope issues**: Declared variables in wrong scope

The fixed version uses the correct pattern: `getline()` to get each line, then `stringstream` to parse that specific line.