# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from dji_sdk/MissionWaypointAction.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class MissionWaypointAction(genpy.Message):
  _md5sum = "940a2c85852b1259dcafa1d9b9ce78fd"
  _type = "dji_sdk/MissionWaypointAction"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """# action_repeat
# lower 4 bit: Total number of actions
# hight 4 bit: Total running times
uint8 action_repeat
uint8[16] command_list
uint16[16] command_parameter
"""
  __slots__ = ['action_repeat','command_list','command_parameter']
  _slot_types = ['uint8','uint8[16]','uint16[16]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       action_repeat,command_list,command_parameter

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(MissionWaypointAction, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.action_repeat is None:
        self.action_repeat = 0
      if self.command_list is None:
        self.command_list = b'\0'*16
      if self.command_parameter is None:
        self.command_parameter = [0] * 16
    else:
      self.action_repeat = 0
      self.command_list = b'\0'*16
      self.command_parameter = [0] * 16

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      buff.write(_get_struct_B().pack(self.action_repeat))
      _x = self.command_list
      # - if encoded as a list instead, serialize as bytes instead of string
      if type(_x) in [list, tuple]:
        buff.write(_get_struct_16B().pack(*_x))
      else:
        buff.write(_get_struct_16s().pack(_x))
      buff.write(_get_struct_16H().pack(*self.command_parameter))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      start = end
      end += 1
      (self.action_repeat,) = _get_struct_B().unpack(str[start:end])
      start = end
      end += 16
      self.command_list = str[start:end]
      start = end
      end += 32
      self.command_parameter = _get_struct_16H().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      buff.write(_get_struct_B().pack(self.action_repeat))
      _x = self.command_list
      # - if encoded as a list instead, serialize as bytes instead of string
      if type(_x) in [list, tuple]:
        buff.write(_get_struct_16B().pack(*_x))
      else:
        buff.write(_get_struct_16s().pack(_x))
      buff.write(self.command_parameter.tostring())
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      start = end
      end += 1
      (self.action_repeat,) = _get_struct_B().unpack(str[start:end])
      start = end
      end += 16
      self.command_list = str[start:end]
      start = end
      end += 32
      self.command_parameter = numpy.frombuffer(str[start:end], dtype=numpy.uint16, count=16)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_B = None
def _get_struct_B():
    global _struct_B
    if _struct_B is None:
        _struct_B = struct.Struct("<B")
    return _struct_B
_struct_16H = None
def _get_struct_16H():
    global _struct_16H
    if _struct_16H is None:
        _struct_16H = struct.Struct("<16H")
    return _struct_16H
_struct_16B = None
def _get_struct_16B():
    global _struct_16B
    if _struct_16B is None:
        _struct_16B = struct.Struct("<16B")
    return _struct_16B
_struct_16s = None
def _get_struct_16s():
    global _struct_16s
    if _struct_16s is None:
        _struct_16s = struct.Struct("<16s")
    return _struct_16s
