var NativeExtension = require('bindings')('NativeExtension');
module.exports = NativeExtension;

test('Check Number of Monitors', () => {
	expect(NativeExtension.monitor()).toBe(1);
});

test('Check Last Input Time', () => {
	expect(NativeExtension.lastinputtime()).toBe(0);
});