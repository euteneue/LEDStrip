# API Documentation

## Technologies used
This API is built on a REST interface, i.e. all API functions are implemented using HTTP(S) GET, POST, PUT and DELETE.


## Function Catalog

### LED Strip Status
Liefert den aktuellen Status des LED Strip zurück.

**URL** : `/status`

**Method** : `GET`

**Eingabedaten**

`Keine.`

**Beispiel**

## Antwort bei Erfolg

**Code** : `200 OK`

**Content example**

```json
{
    "on":       "1",
    "mode":     "laufschrift",
    "color":    "#FFFFFF",
    "payload":  "On Air"
}
```
