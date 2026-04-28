# Character Randomizer Server (Linux)

This project is a cross-platform ASP.NET server built with .NET, designed to run on Linux environments.

---

## 🚀 Running the Server

### Using .NET CLI

1. Open a terminal in:
.../ServerLinux

2. Run:

```bash
dotnet run --project CharacterRandomizerServerLinux.csproj
```

## 🌐 Default Endpoint

The server binds to:
```https://0.0.0.0:44373```

## ⚙️ Using Launch Profiles
You can also run the server using profiles defined in launchSettings.json.

```bash
dotnet run --project CharacterRandomizerServerLinux.csproj --launch-profile http
```

### HTTPS
```bash
dotnet run --project CharacterRandomizerServerLinux.csproj --launch-profile https
```