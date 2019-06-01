class ArduinoBT {

	static init() {

		this.button = document.querySelector('button')
		this.button.onclick = () => {

			navigator.bluetooth.requestDevice({ acceptAllDevices: true })
				.then((device) => {
					
					return device.gatt.connect();
				})
		}
		
	}
}