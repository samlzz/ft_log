# ft_log — Minimal Logging Library for C++98

`ft_log` is a small, dependency-free logging library written in **C++98**.  
It was originally designed for my 42 projects (notably **ftpp** and **webserv**) and aims to provide a clean, lightweight, configurable logging system that can be integrated into any C or C++ codebase.

Its goal is simplicity: a tiny footprint, fast integration, and a clean API with optional ANSI colors, categories, and scope-based tracing.


## Table of Contents

- [Features](#features)
- [Installation](#installation)
  - [Option 1 — One-line install](#option-1--one-line-install-recommended)
  - [Option 2 — Manual clone](#option-2--manual-clone)
- [Minimal Usage Example](#minimal-usage-example)
- [API Overview](#api-overview)
  - [Logging levels](#logging-levels)
  - [Global configuration](#global-configuration)
  - [Logging helpers](#logging-helpers)
  - [RAII scope tracing](#raii-scope-tracing)
- [Architecture Overview](#architecture-overview)
- [License](#license)

---

## Features

- ✔ **Header-only public API**  
- ✔ **Configurable global log level**
- ✔ **Category-based filtering**
- ✔ **Optional color output**
- ✔ **Optional level prefix display**
- ✔ **Indent-aware logging**
- ✔ **RAII-based scope tracing** via `LogScope`
- ✔ **Null-stream when logging is disabled** (zero-overhead)

---

## Installation

### Option 1 — One-line install (recommended)

Inside your project directory:

```bash
bash <(curl -s https://raw.githubusercontent.com/samlzz/ft_log/master/sync_ft_log.sh)
````

This installs the library into a local `ft_log/` directory (or replaces the existing one).

> The script clones the repo, removes with confirmation `.git/` and the script itself, and leaves a clean vendored copy.

---

### Option 2 — Manual clone

```bash
git clone https://github.com/samlzz/ft_log.git
```

To compile librairie:
```bash
make -C 'ft_log'
```

Then include the headers and link the static library if needed:

```cpp
#include "ft_log/ft_log.hpp"
```

---

## Minimal Usage Example

```cpp
#include "ft_log/ft_log.hpp"

int main() {
    // Enable the category you want to use
    ft_log::enableCategory("core");
    ft_log::setLevel(ft_log::LOG_TRACE);       // Show everything
    ft_log::setColorEnabled(false);     /// Disabled colored output
    ft_log::setShowLevel(true);        // Show [INFO], [DEBUG], ...

    ft_log::log("core", ft_log::LOG_INFO) << "Hello from ft_log!" << std::endl;

    {
        ft_log::LogScope _scope("core", "initialization", ft_log::LOG_DEBUG);
        ft_log::indentedLog("core", ft_log::LOG_DEBUG) << "Preparing system..." << std::endl;
    }

    return 0;
}

```

The output may look like:

```
[INFO] Hello from ft_log!
enter initialization
  Preparing system...
exit initialization
```

> Color applied by default, need to explicitly disabled.

---

## API Overview

All public headers are in `include/ft_log/`.

### Logging levels

Header: `level.hpp`

```cpp
enum e_log_level {
    LOG_TRACE,
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR,
    LOG_OFF
};
```

### Global configuration

Header: `LogConfig.hpp`

* `setLevel(e_log_level)`
* `setOutputStream(std::ostream&)`
* `setColorEnabled(bool)`
* `setShowLevel(bool)`
* Category control:

  * `enableCategory("name")`
  * `disableCategory("name")`
  * `isCategoryEnabled("name")`

### Logging helpers

Header: `LogOp.hpp`

* `log(category, level)` — returns an `ostream` (or null stream)
* `indentedLog(category, level)` — logs with current indentation
* `enabled(category, level)`
* `color(text, ansiCode)`

### RAII scope tracing

Header: `LogScope.hpp`

```cpp
LogScope(const char *category, const char *name, e_log_level level = LOG_TRACE);
```

Creates:

```
enter myFunction
  [...]
exit myFunction
```

Indentation is tracked globally.

---

## Architecture Overview

```
ft_log/
├── include/ft_log/
│   ├── ft_log.hpp           # Public umbrella header
│   ├── level.hpp            # Log levels + operator<<
│   ├── LogConfig.hpp        # Global configuration API
│   ├── LogOp.hpp            # Logging helpers
│   ├── LogScope.hpp         # RAII tracing
│   ├── AnsiColor.hpp        # Compile-time ANSI codes
│   └── internal/            # Private implementation details
│       ├── Logger.hpp       # Core singleton logger
│       └── LevelDisplay.hpp # Level label/color mapping
└── src/ft_log/
    ├── Log.cpp              # Public API implementation
    ├── Logger.cpp           # Core logger implementation
    ├── LogScope.cpp         # Scope implementation
    └── level.cpp            # Level helpers
```

Public code is cleanly separated from internal implementation.
User code should **only** include the public headers.

---

## License

The project is licensed under the **GNU LGPL v3**.
You may use it in open-source or proprietary software as long as modifications to the library itself remain LGPL-licensed.
