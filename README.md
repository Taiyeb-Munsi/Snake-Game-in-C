# Snake Game (Ncurses)

This is a lightweight implementation of the traditional Snake game. It features two difficulty models, a scoring system, and simple terminal controls.

---

## What it does

Use the **WASD** keys to control the snake and eat `'*'` to grow. It has two modes:

* **easy mode**: The snake wraps around the edges.
* **hard mode**: The snake can hit the edges and lose.

---

## Tech Used

* C Language
* Ncurses

---

## Running Locally

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/Taiyeb-Munsi/Snake-Game-in-C.git](https://github.com/Taiyeb-Munsi/Snake-Game-in-C.git)
    cd Snake-Game-in-C
    ```

2.  **Build the project:**
    ```bash 
    make
    ```

3.  **Launch the game:**
    * **easy mode:**
        ```bash 
        ./snake -e 
        ```
    * **hard mode:**
        ```bash
        ./snake -h
        ```

---

## Controls 

* **W/A/S/D**: Move up, left, down, right
* **P**: Pause / Unpause
* **R**: Restart (Only after losing)
* **Q**: Quit game
