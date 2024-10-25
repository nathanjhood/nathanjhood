import type RN = require('react-native');
import ReactNative = require('react-native');
import type React = require('react');

const { Pressable, Text }: typeof RN = ReactNative;

type AppButtonProps = React.PropsWithChildren<{
  className?: string;
  textClassName?: string;
  label?: string;
}>

const AppButton = (props?: AppButtonProps): JSX.Element => {
  return (
    <Pressable className={props && props.className || ''}>
      <Text className={props && props.textClassName || ''}>{props?.label || 'click'}</Text>
    </Pressable>
  );
};

export = AppButton;
