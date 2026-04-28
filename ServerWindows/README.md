# Character Randomizer Server

This project is an ASP.NET Web API / MVC application targeting **.NET Framework 4.7.2**.  
It requires **Windows** to run due to its dependency on `System.Web`.

---

## 🚀 Running the Server

### Recommended (Visual Studio)

1. Open `CharacterRandomizerServer.sln` in Visual Studio  
2. Set the project as **Startup Project** (if not already)  
3. Press:
   - `F5` to run with debugging  
   - `Ctrl + F5` to run without debugging  

---

## 🌐 Default Launch Settings

- Uses **IIS Express**
- Default port (from project config): `44373`

After starting, the requested APIs should be redirected to:
```https://localhost:44373```

---

## 🖥️ Running via Command Line

Use a **Windows Developer Command Prompt**:

### Build
```bash
msbuild CharacterRandomizerServer.sln /p:Configuration=Debug
```
---
## Run with IIS Express
```iisexpress /path:"C:\path\to\ServerWindows" /port:44373```