import type RN = require('react-native');
import type React = require('react');
import rn = require("react-native");
import react = require("react");

declare namespace AsyncButton {
  type Props = React.PropsWithChildren<RN.PressableProps & {
    // Custom props can go here...
  }>;
  type Component = JSX.Element | null;
};

interface AsyncButton {
  (props: AsyncButton.Props): AsyncButton.Component
}

const AsyncButton: AsyncButton = (props: AsyncButton.Props): AsyncButton.Component => {
  //
  const {
    onPress,
    style,
    children,
    ...restProps
  }: AsyncButton.Props = props;
  const { Animated, Pressable, StyleSheet, View }: typeof RN = rn;

  const progress: RN.Animated.Value = react.useRef(new Animated.Value(0)).current
  const opacity: RN.Animated.Value = react.useRef(new Animated.Value(1)).current

  const handlePress = (e: RN.GestureResponderEvent): void => {
    progress.setValue(0)
    opacity.setValue(1)

    onPress?.(e)

    Animated.timing(progress, {
      toValue: 1,
      duration: 1000,
      useNativeDriver: false,
    }).start(({ finished }) => {
      if (!finished) {
        return
      }

      Animated.timing(opacity, {
        toValue: 0,
        duration: 200,
        useNativeDriver: false,
      }).start()
    })
  }

  const progressInterpolate: RN.Animated.AnimatedInterpolation<string | number> = progress.interpolate<string | number>({
    inputRange: [0, 1],
    outputRange: ["0%", "100%"],
    extrapolate: "clamp",
  })

  const progressStyle: RN.Animated.WithAnimatedObject<RN.ViewStyle> = {
    width: progressInterpolate,
    opacity,
  }

  const styles: { [key: string | symbol]: RN.ViewStyle } = StyleSheet.create<{
    progress: RN.ViewStyle;
  }>({
    progress: {
      position: "absolute",
      top: 0,
      bottom: 0,
      left: 0,
      backgroundColor: "rgba(112,76,182, 0.15)",
    },
  })

  return (
    <Pressable style={style} onPress={handlePress} {...restProps}>
      <View style={StyleSheet.absoluteFill}>
        <Animated.View style={[styles['progress'], progressStyle]} />
      </View>
      {children}
    </Pressable>
  ) satisfies JSX.Element;
}

export = AsyncButton
