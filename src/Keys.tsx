import type ReactNative = require("react-native");
import reactNative = require("react-native");

const Keys = () => {
  const {
    SafeAreaView,
    Text,
    View,
    Pressable,
    StyleSheet,
    useWindowDimensions,
    useColorScheme,
  }: typeof ReactNative = reactNative;

  const { width, height } = useWindowDimensions();

  const colorScheme = useColorScheme();

  const colorBlack = "#000000";
  const colorWhite = "#FFFFFF";

  const bgColorResponsive = colorScheme === "light" ? colorWhite : colorBlack;
  const colorResponsive = colorScheme === "light" ? colorBlack : colorWhite;

  const keys: string[] = ['c', 'd', 'e', 'f', 'g', 'a', 'b', 'c'];
  const colors: string[] = ['blue', 'green', 'red', 'yellow', 'purple', 'cyan', 'pink', 'magenta']

  const blackKeys: string[] = ['c#', 'd#', 'f#', 'g#', 'a#'];
  return (
    <View
      style={{
        flex: 1,
        alignItems: 'center',
        justifyContent: 'center',
      }}
    >
      <View>
        {keys.map<JSX.Element>((key, idx) => {
          return (
            <View style={{ backgroundColor: colors[idx], zIndex: 1 }}>
              <Text>
                <Text>{key.toString()}</Text>
              </Text>
            </View>
          )
        })}
      </View>
      <View>
        {blackKeys.map<JSX.Element>((key, idx) => {
          return (
            <View style={{ backgroundColor: colors[idx], zIndex: 2, margin: -16 }}>
              <Text>
                <Text>{key.toString()}</Text>
              </Text>
            </View>
          )
        })}
      </View>
    </View>
  )
}

export = Keys;
