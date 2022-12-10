# API Documentation

## Technologies used
This API is built on a REST interface, i.e. all API functions are implemented using HTTP(S) GET, POST, PUT and DELETE.

## URL Endpoint

Der Service ist nur über das lokale WLAN an das Netzwerk angebunden und kann entsprechend nur aus dem Heimnetz erreicht werden.

**URL Base** : 

`http://192.168.0.191`

# Function Catalog

## LED Strip Status
Liefert den aktuellen Status des LED Strip zurück.

**URL** : `/ledstrip`

**Request Method** : `GET`

**Eingabedaten**

`Keine.`

**Beispiel**

## Antwort bei Erfolg

**HTTP Response** : `200 OK`

**Content example**

```json
{
    "on":       "1",
    "mode":     "marquee",
    "color":    "#FFFFFF",
    "brightness": 32,
    "payload":  "On Air"
}
```

## Switch ON/OFF
Schaltet den LED Strip an oder aus

**URL** : `/ledstrip/power`

**Request Method** : `POST`

**Eingabedaten**

```json
{
    "on":       "[either 0 for switching OFF or 1 for switching ON]"
}
```

**Beispiel**

```json
{
    "on":       "0"
}
```

## Antwort bei Erfolg

**HTTP Response** : `200 OK`

**Content example**

`Keine.`

## Set Marquee
Schaltet den LED Strip in den Modus "Laufschrift"

**URL** : `/ledstrip/marquee`

**Request Method** : `POST`

**Eingabedaten**

```json
{
    "text":       "[String containing the text to be displayed <= 100 chars]",
    "color":      "[The color to be used as #RRGGBB two digit hex values per color]",
    "brightness": "[A value between 0 (off) and 255 (full brightness - not recommended!)]"
}
```

**Beispiel**

```json
{
    "text":       "On Air! Do not disturb!",
    "color":      "#FF2222",
    "brightness": 32
}
```

## Antwort bei Erfolg

**HTTP Response** : `200 OK`

**Content example**

`Keine.`

## Set Solid Color
Schaltet den LED Strip in den Modus "Vollfarbe"

**URL** : `/ledstrip/solidcolor`

**Request Method** : `POST`

**Eingabedaten**

```json
{
    "color":      "[The color to be used as #RRGGBB two digit hex values per color]",
    "brightness": "[A value between 0 (off) and 255 (full brightness - not recommended!)]"
}
```

**Beispiel**

```json
{
    "color":      "#00AA55",
    "brightness": 16
}
```

## Antwort bei Erfolg

**HTTP Response** : `200 OK`

**Content example**

`Keine.`

## Rainbow Wave
Schaltet den LED Strip in den Modus "Durchlaufende Regenbogenfarben"

**URL** : `/ledstrip/rainbow`

**Request Method** : `POST`

**Eingabedaten**

```json
{
    "speed":      "[A value between 1 and 10]",
    "brightness": "[A value between 0 (off) and 255 (full brightness - not recommended!)]"
}
```

**Beispiel**

```json
{
    "speed":      3,
    "brightness": 16
}
```

## Antwort bei Erfolg

**HTTP Response** : `200 OK`

**Content example**

`Keine.`
