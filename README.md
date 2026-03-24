# 🖥️ Linux System Monitor (C)

A lightweight **terminal-based system monitor** written in C, inspired by tools like `htop`.
It displays real-time system statistics such as **CPU usage, RAM usage, and Disk usage** using Linux system files.

---

## 🚀 Features

* 📊 Real-time **CPU Usage**
* 🧠 Live **RAM Usage**
* 💾 **Disk Usage** monitoring
* 🔄 Auto-refresh every second
* ⚡ Lightweight and fast (no external dependencies)
* 🐧 Uses Linux `/proc` filesystem

---

## 🛠️ Tech Stack

* **Language:** C
* **OS:** Linux (Tested on Arch Linux)
* **Concepts Used:**

  * File handling
  * `/proc` filesystem
  * System calls (`statvfs`)
  * Real-time data processing

---

## 📂 Project Structure

```
.
├── monitor.c     # Main source code
└── README.md     # Project documentation
```

---

## ⚙️ Installation & Usage

### 1️⃣ Clone the Repository

```bash
git clone https://github.com/vivekkale109/linux-system-monitor.git
cd linux-system-monitor
```

### 2️⃣ Compile the Code

```bash
gcc monitor.c -o monitor
```

### 3️⃣ Run the Program

```bash
./monitor
```

---

## 📸 Preview

```
===== SYSTEM MONITOR =====

CPU Usage: 23.45%
RAM Usage: 61.12%
Disk Usage: 40.78%

Press Ctrl+C to exit...
```

---

## 🧠 How It Works

* **CPU Usage** → Read from `/proc/stat`
* **RAM Usage** → Read from `/proc/meminfo`
* **Disk Usage** → Using `statvfs()` system call

---

## 🔥 Future Improvements

* [ ] Add colored output (ANSI colors)
* [ ] Add bar graphs (like `htop`)
* [ ] Show per-core CPU usage
* [ ] Add process viewer
* [ ] Keyboard controls (quit, refresh rate)
* [ ] UI using `ncurses`

---

## 🤝 Contributing

Contributions are welcome!

1. Fork the repo
2. Create a new branch
3. Make your changes
4. Submit a pull request

---

## 📜 License

This project is open-source and available under the **MIT License**.

---

## 👨‍💻 Author

**Vivek Kale**
🔗 GitHub: https://github.com/vivekkale109

---

⭐ If you like this project, don't forget to star the repo!
