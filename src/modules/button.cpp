#include "modules/button.h"

namespace {
	int buttonReading;
	int buttonState;          // Current reading from the input pin.
	int lastButtonState = 0;  // Previous reading from the input pin.

	// We use unsigned longs because the time, measured in milliseconds,
	// will quickly become a bigger number than can be stored in an int.
	unsigned long lastDebounceTime = 0;  // Last time the button pin was toggled.
	unsigned long debounceDelay = 50;    // Debounce time; increase it if the output flickers
}

namespace button {

	void init() {
		pinMode(BUTTON_PIN, INPUT);
	}

	void loop() {
		// Read the state of the button.
		buttonReading = digitalRead(BUTTON_PIN);

		// If the button state changed.
		if (buttonReading != lastButtonState) {
			// Reset the debouncing timer.
			// We track time in order to avoid noise state changes.
			lastDebounceTime = millis();
		}
	}

	int getLastDebounceTime() {
		return lastDebounceTime;
	}

	int getDebounceDelay() {
		return debounceDelay;
	}

	bool buttonStateChanged() {
		return buttonReading != buttonState;
	}

	bool buttonStateHigh() {
		return buttonState == HIGH;
	}

	void updateBottonState() {
		buttonState = buttonReading;
	}

	void updateLastButtonState() {
		lastButtonState = buttonReading;
	}
}