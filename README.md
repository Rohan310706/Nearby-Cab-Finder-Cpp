# 🚖 Nearby Cab Finder using C++

This is a simple C++ console application that finds nearby cabs using the **Great Circle Distance** formula. It takes a user's location and shows the nearest available cabs sorted by distance.

---

## 🔧 Features

- Uses the **Haversine formula** to calculate distances between two geographic points.
- Allows dynamic input of user and cab locations.
- Displays the closest cabs to the user.
- Modular and beginner-friendly code structure.

---

## 📁 File Structure

- `main.cpp` – Core logic of the program
- `cab_data.csv` – (Optional) Sample file containing cab coordinates
- `README.md` – Project documentation

---

## 📥 Sample Input

```
User location: (28.6139, 77.2090) // New Delhi
Cab1: (28.7041, 77.1025)  // Delhi NCR
Cab2: (28.5355, 77.3910)  // Noida
Cab3: (28.4595, 77.0266)  // Gurgaon
```

---

## 📤 Sample Output

```
Cab at (28.7041, 77.1025) - Distance: 12.5 km
Cab at (28.5355, 77.3910) - Distance: 17.8 km
Cab at (28.4595, 77.0266) - Distance: 22.3 km
```

---

## 🚀 How to Run

### Compile
```bash
g++ main.cpp -o cabfinder
```

### Run
```bash
./cabfinder
```

---

## 🧠 Future Improvements

- Read cab data from a CSV file
- Add ETA calculations
- Support for different types of cabs (Sedan, Mini, SUV)
- GUI using simple console-based interface

---

## 📎 Author

Rohan Bansal – COPC student  @ Thapar University  
🔗 [GitHub Profile] (https://github.com/Rohan310706)

